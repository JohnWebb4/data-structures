#!/bin/bash

cat <<\EOF
Building app...
EOF


cmake .
make

cat <<\EOF
Done building
EOF

exit 0
