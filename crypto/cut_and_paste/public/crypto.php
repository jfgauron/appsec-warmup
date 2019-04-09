<?php

$key = "6d0sV3MJ2w6ywk5Q";

function encrypt($data) {
    global $key;
    return bin2hex(mcrypt_encrypt(
        MCRYPT_RIJNDAEL_128,
        $key,
        $data,
        MCRYPT_MODE_ECB
    ));
}

function decrypt($data) {
    global $key;
    return mcrypt_decrypt(
        MCRYPT_RIJNDAEL_128,
        $key,
        hex2bin($data),
        MCRYPT_MODE_ECB
    );
}
