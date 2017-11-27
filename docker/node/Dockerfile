FROM darkxahtep/dht:latest as build-env

FROM arm32v6/node:9.2.0-9.2.0-alpine
WORKDIR /app
COPY --from=build-env ./dht_reader .
COPY --from=build-env ./dht_reader2 .

ENTRYPOINT [ "/bin/sh" ]