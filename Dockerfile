ARG VERSION=010422
FROM jac18281828/cppdev:${VERSION} 

ARG PROJECT=enigma
# build project
WORKDIR /workspaces/${PROJECT}

COPY src src/
COPY test test/
COPY CMakeLists.txt .    

ARG BUILD=build

ARG TYPE=RELEASE

#build
ENV MAKEFLAGS=-j8
RUN cmake -H. -B${BUILD} -DPROJECT_NAME=${PROJECT} -DCMAKE_BUILD_TYPE=${TYPE} -DCMAKE_VERBOSE_MAKEFILE=on "-GUnix Makefiles"
RUN cmake --build ${BUILD} --verbose --config ${TYPE}
ENV CTEST_OUTPUT_ON_FAILURE=1
RUN (cd ${BUILD} && ctest)
ENV PROJECT_NAME=${PROJECT}
CMD build/${PROJECT_NAME} 
