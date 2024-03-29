FROM debian:bullseye

# 패키지 설치
RUN apt-get update && apt-get install -y php7.4-fpm php7.4-mysql
RUN apt-get install -y mariadb-client
RUN apt-get install -y curl
RUN apt-get install -y vim
RUN apt-get install -y sudo 

RUN mkdir -p /var/www/html
RUN mkdir -p /run/php

RUN cd /var/www/html/ &&\
    curl -O https://wordpress.org/wordpress-5.7.8.tar.gz && \
    tar -xzvf wordpress-5.7.8.tar.gz && \
    rm wordpress-5.7.8.tar.gz && \
    mv wordpress/* /var/www/html && \
    rm -rf wordpress

RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar
RUN chmod +x wp-cli.phar
RUN mv wp-cli.phar /usr/local/bin/wp

RUN chown -R www-data:www-data /var/www/html
RUN chmod -R 755 /var/www/html
RUN chown -R www-data:www-data /run/php
RUN chmod -R 755 /run/php

COPY tools/script.sh /usr/local/bin/script.sh
RUN chmod 755 /usr/local/bin/script.sh

COPY ./tools/www.conf /etc/php/7.4/fpm/pool.d/www.conf
RUN rm -rf wordpress-5.7.8.tar.gz /var/www/wordpress

CMD ["sh", "/usr/local/bin/script.sh"]