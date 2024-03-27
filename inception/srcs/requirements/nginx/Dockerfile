FROM debian:bullseye

RUN apt-get update && apt-get install -y wget openssl nginx
RUN apt-get install -y vim
RUN mkdir -p /etc/ssl/private
RUN mkdir -p /etc/ssl/certs
RUN openssl req -x509 -nodes -days 365 -newkey rsa:2048 -keyout /etc/ssl/private/nginx-selfsigned.key -out /etc/ssl/certs/nginx-selfsigned.crt -subj "/C=KR/ST=Seoul/L=Paris/O=42/OU=42/CN=localhost"

COPY ./conf/default /etc/nginx/sites-available
CMD ["nginx", "-g", "daemon off;"]
