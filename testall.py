#!/bin/python3

import logging
import sys
import os
import yaml
import re
from subprocess import check_output as commond
from os.path import join, isfile, isdir, dirname

EXCLUDE_DIRS = [
  './.vscode',
  './.git',
  '.vscode',
  '.git'
]

def getLogger(level = 'info'):
  FORMAT = '%(asctime)-15s [%(name)-12s] %(levelname)-8s %(message)s'
  logging.basicConfig(format=FORMAT)
  logger = logging.getLogger(sys.argv[0])
  log_level = logging.DEBUG if level.lower() == 'debug' else logging.INFO
  logger.setLevel(log_level)

  return logger

def recurse_dir(path = '.'):
  files = [ join(path, f) for f in os.listdir(path) ]
  regular_files = [f for f in files if isfile(f) and re.search('test-.*.yaml', f)]
  dirs = [d for d in files if ( isdir(d) and (d not in EXCLUDE_DIRS) )]
  
  for d in dirs:
    sub_dir_files = recurse_dir(d)
    regular_files.extend(sub_dir_files)

  return regular_files

def get_test_files():
  test_files = recurse_dir()
  return test_files

def testOne(test_file):

  test_cases = yaml.full_load( open(test_file) )
  for name in test_cases:
    print('+' * 80)
    logger.info('testing %s', name)

    src_dir = dirname(test_file)
    src_files = test_cases[name];
    src_file_list = [src_files] if isinstance(src_files, str) else src_files
    src_files_with_path = [ join(src_dir, f) for f in src_file_list ]
    logger.debug('title: %s, files: %s', name, ', '.join(src_files_with_path));
    
    compile_cmd = ['g++'] + src_files_with_path
    compile_cmd.extend(['-o', name])
    logger.debug('compile command: %s', ' '.join(compile_cmd))
    output = commond(compile_cmd)
    logger.debug('compile result: %s', repr(output))

    run_executable_cmd = ['./' + name]
    logger.debug('run_executable_cmd: %s', run_executable_cmd)

    os.system(' '.join(run_executable_cmd))
    logger.info('finished testing %s.\n%s\n', name, '-' * 80)

    os.remove(name)

def test_all(test_filter = '.*'):
  test_files = get_test_files()
  logger.debug('all test files: %s', ', '.join(test_files))
  for test in test_files:
    if test_file_filter and re.search(test_filter, test) == None:
      logger.debug('skip test %s', test)
      continue

    logger.info('test file: %s', test);
    testOne(test)

if __name__ == '__main__':
  level = 'info' if len(sys.argv) < 3 else sys.argv[2]
  logger = getLogger(level)

  test_file_filter = '.*' if len(sys.argv) < 2 else sys.argv[1]
  test_all(test_file_filter)
