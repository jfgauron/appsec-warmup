FROM php:7.0-apache

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y libmcrypt-dev
RUN docker-php-ext-install mcrypt

COPY public /var/www/html/