FROM ubuntu:18.04

RUN apt-get update && apt-get upgrade -y

RUN apt-get install -y supervisor apache2 memcached
RUN DEBIAN_FRONTEND=noninteractive apt-get install -y php \
    libapache2-mod-php php-curl php-memcached
RUN mkdir -p /var/log/supervisor

COPY 000-default.conf /etc/apache2/sites-available/000-default.conf
COPY supervisord.conf /etc/supervisor/conf.d/supervisord.conf
COPY apache2.conf /etc/supervisor/conf.d/apache2.conf
COPY memcached.conf /etc/supervisor/conf.d/memcached.conf

RUN service apache2 restart

COPY php.ini /etc/php/7.2/apache2/php.ini
COPY public /var/www/html/
RUN chown -R root:www-data /var/www/html
RUN chmod -R 755 /var/www/html

COPY flag /flag
RUN chown -R root:root /flag
RUN chmod 111 /flag

ENTRYPOINT ["/usr/bin/supervisord"]