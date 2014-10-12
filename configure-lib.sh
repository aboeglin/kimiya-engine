#!/bin/sh
#
# Compile and set libraries.
#

cd libpng/
./configure --enable-static
make
cp .libs/libpng.a ../lib/bin/

cd ../libjpeg/
ln /usr/bin/glibtool libtool
./configure --enable-static
make
cp .libs/libjpeg.a ../lib/bin/

cd ../zlib/
./configure --enable-static
make
cp libZ.a ../lib/bin/