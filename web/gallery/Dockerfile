FROM php:7.0-apache

RUN apt-get update && apt-get install -y

COPY public /var/www/html/

RUN chown -R root:www-data /var/www/html/uploads
RUN chmod -R 733 /var/www/html/uploads