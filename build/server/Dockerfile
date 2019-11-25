# build stage
FROM golang:1.13-stretch as builder
WORKDIR /server
COPY . .
ENV GO111MODULE=on
RUN CGO_ENABLED=0 GOOS=linux go build -o server

# runtime stage
FROM alpine:latest
WORKDIR /server
COPY --from=builder /server/server .
COPY --from=builder /fun-cloud-api/configs .
RUN set -a && source ./configs/container/dev.env
CMD ["/server"]