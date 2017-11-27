FROM darkxahtep/dht:latest as build-env

FROM arm32v6/node:9.2.0-alpine
WORKDIR /app
COPY --from=build-env /app/dht_reader .
