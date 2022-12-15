FROM ubuntu:latest

RUN DEBIAN_FRONTEND="noninteractive" apt-get update && apt-get -y install tzdata

RUN apt-get update \
&& apt-get install -y ssh \
    build-essential \
    libboost-all-dev \
    git \
    cmake \
    vim \
    net-tools \
    gdb \
    clang \
    rsync \
    tar \
&& apt-get clean

WORKDIR /work
