FROM debian

RUN apt update
RUN apt upgrade -yqq
RUN apt install -yqq \
    build-essential \
    git \
    m4 \
    automake \
    scons \
    zlib1g \
    zlib1g-dev \
    libprotobuf-dev \
    protobuf-compiler \
    libprotoc-dev \
    libgoogle-perftools-dev \
    python-dev \
    python

RUN apt install -yqq \
    python-pip

RUN pip install six

RUN apt install -yqq \
    libboost-all-dev
