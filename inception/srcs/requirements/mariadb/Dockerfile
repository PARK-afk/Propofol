FROM debian:bullseye

RUN apt-get update && apt-get install -y mariadb-server
RUN apt-get install -y vim
RUN apt-get clean
RUN rm -rf /var/lib/apt/lists/* #발생 가능한 에러 존재

COPY tools/script.sh .
RUN chmod +x script.sh

COPY conf/50-server.cnf /etc/mysql/mariadb.conf.d/50-server.cnf
RUN chown -R mysql:mysql /etc/mysql/mariadb.conf.d
RUN chmod 755 /etc/mysql/mariadb.conf.d
ENTRYPOINT ["sh", "./script.sh"]
