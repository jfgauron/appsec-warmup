FROM ubuntu:18.04

RUN apt-get update && apt-get upgrade -y
RUN apt-get install xinetd vim net-tools -y

RUN useradd challenge
RUN mkdir /app
COPY ./public/keepass3 /app/keepass
COPY ./config /etc/xinetd.d/keepass
COPY ./flag /flag

RUN chmod -R 555 /app
RUN chmod 555 /flag

CMD ["/usr/sbin/xinetd", "-dontfork"]