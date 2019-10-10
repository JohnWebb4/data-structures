#!/bin/bash

cat <<\EOF
Building app...
EOF


cmake .
make

if ! ./runTests ; then
  cat <<\EOF
Error running tests
EOF
exit 1
fi

cat <<\EOF
Done building
EOF
