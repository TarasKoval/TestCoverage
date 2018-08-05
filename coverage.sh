mkdir build
cd build
cmake ..
make 
make tests_coverage
google-chrome coverage/index.html
