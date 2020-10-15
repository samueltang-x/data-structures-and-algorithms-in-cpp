#!/bin/bash

set -o errexit -o noclobber -o nounset -o pipefail

function test_all() {
  local work_dir=${1:-.}
  local prev_dir=$(pwd)

  cd $work_dir

  for f in $(find . -name 'test-*.sh')
  do
    local file_dir=$(dirname $f)
    local file_name=$(basename $f)
    cd $file_dir
    echo
    pwd
    bash $file_name
    cd - > /dev/null
  done
  cd $prev_dir
}

function main() {
  local scriptName=$(realpath ${BASH_SOURCE[0]})
  local workDir=$(dirname $scriptName)
  test_all $workDir
}

echo ${BASH_SOURCE[0]}
main
