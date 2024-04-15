# Use an official Ubuntu base image
FROM ubuntu:latest

# Set the maintainer label
LABEL maintainer="sharifbeigymohammad@gmail.com"

# Install system dependencies
RUN apt-get update && apt-get install -y \
    g++ \
    make \
    cmake \
    libsfml-dev \
    libncurses5-dev \
    libncursesw5-dev \
    git \
    bash \
    && rm -rf /var/lib/apt/lists/*

# Clone the IUSTZ project repository
RUN git clone https://github.com/MohammadMahdi-Sharifbeigy/IUSTZ

# Clone the FTXUI repository
RUN git clone https://github.com/ArthurSonzogni/FTXUI.git

# Create a build directory and run CMake to configure the project
RUN mkdir -p FTXUI/build && cd FTXUI/build && \
    cmake .. && \
    # Build the project
    make && \
    # Install the library
    make install

# Set the working directory
WORKDIR /IUSTZ

# copy working directory
COPY . /IUSTZ

# Build your application
RUN make

# Copy source code into the image
COPY . /game

# Command to run when starting the container
CMD ["./game"]
