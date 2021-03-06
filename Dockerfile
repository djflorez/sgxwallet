FROM skalenetwork/sgxwallet_base:latest
WORKDIR /usr/src/sdk

COPY *.cpp ./
COPY *.h ./
COPY *.txt ./
COPY *.c ./
COPY *.am ./
COPY *.hpp ./
COPY *.gmp ./
COPY *.ac ./
COPY *.json ./
COPY docker ./docker
COPY build-aux ./build-aux
COPY  cert ./cert
COPY jsonrpc ./jsonrpc

COPY leveldb ./leveldb
COPY m4 ./m4
COPY scripts ./scripts
COPY secure_enclave ./secure_enclave
COPY spdlog ./spdlog
COPY SGXWALLET_VERSION ./

RUN autoreconf -vif
RUN libtoolize --force
RUN aclocal
RUN autoheader || true
RUN automake --force-missing --add-missing
RUN autoconf
RUN ./configure
### RUN cd libBLS; cmake -H. -Bbuild; cmake --build build -- -j$(nproc);
RUN make

RUN mkdir /usr/src/sdk/sgx_data
COPY docker/start.sh ./
ENTRYPOINT ["/usr/src/sdk/start.sh"]
