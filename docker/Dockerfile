#
# docker build --rm -t cpollet/cpp .
# docker run --rm -it \
#   -v `pwd`/..:/sources:ro \
#   -v `pwd`/bw-output:/bw-output \
#   -e CC="gcc-5" \
#   -e CXX="g++-5" \
#   -e CXXFLAGS="-Wall -B/usr/lib/gcc/x86_64-linux-gnu/7" \
#   -e SONAR="true" \
#   cpollet/cpp
#
FROM ubuntu:18.04

RUN apt-get update && \
    apt-get install -y cmake wget unzip \
      libstdc++-5-dev libstdc++-6-dev libstdc++-7-dev libstdc++-8-dev \
      g++-5 g++-6 g++-7 g++-8 \
      clang-5.0 clang-6.0 clang-7 clang-8 && \
    apt-get clean && \
    wget https://sonarcloud.io/static/cpp/build-wrapper-linux-x86.zip && unzip build-wrapper-linux-x86.zip

ADD build.sh /

CMD /build.sh