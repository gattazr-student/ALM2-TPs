#!/bin/bash

is_there=`env | grep ARM_ENVDIR | wc -l`
if [ $is_there == 1 ] 
then
  exit 0
else
  echo "Error : did you forget source setenvarm.csh (or setenvarm.sh) in this shell ?"
  exit 1
fi
