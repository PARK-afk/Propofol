NAME = inception

#clean 빼먹지말아라 all : 
all : setup build

build:
	cd ./srcs && docker compose up --build;

stop:
	cd ./srcs && docker-compose down;

setup:
	cd ./srcs && docker-compose up -d;

clean : stop
	cd ./srcs/ && docker system prune -a;

#fclean : clean
#	rm -f $(NAME)

.PHONY: all clean fclean re bonus build stop setup

# 볼륨을 local 로 빼버리고 
# db 디렉토리 내부에 user 가 안들어온건 문제가 있는거다 찾아가보자
