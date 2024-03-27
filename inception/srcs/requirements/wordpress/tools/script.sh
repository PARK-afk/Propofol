#!/bin/bash

if [ ! -f "/var/www/html/wp-config.php" ]; then
    cd /var/www/html
    pwd
    wp core download --allow-root
    wp config create --allow-root --dbname=${DB_NAME} --dbuser=${DB_USER} --dbpass=${DB_PASSWORD} --dbhost=mariadb --path=/var/www/html
    wp core install --allow-root --url=localhost --title=wordpress --admin_user=${WP_ADMIN_ID} --admin_password=${WP_ADMIN_PW} --admin_email=email@example.com --path=/var/www/html
    wp user create ${WP_USER_ID} user2@example.com --allow-root --role=author --user_pass=${WP_USER_PW} --path=/var/www/html
fi

exec php-fpm7.4 -F