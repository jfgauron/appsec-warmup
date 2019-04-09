<?php

$key = "Od0sV3MJ2w6ywk5Q";

function encrypt($plaintext) {
    global $key;
    $algo = "AES-256-CBC";
    $ivlen = openssl_cipher_iv_length($algo);
    $iv = openssl_random_pseudo_bytes($ivlen);
    $cipher = openssl_encrypt($plaintext, $algo, $key, $options=OPENSSL_RAW_DATA, $iv);
    $ciphertext = base64_encode($iv . $cipher);
    return $ciphertext;
}

function decrypt($ciphertext) {
    global $key;
    $algo = "AES-256-CBC";
    $ciphertext = base64_decode($ciphertext);
    $ivlen = openssl_cipher_iv_length($algo);
    $iv = substr($ciphertext, 0, $ivlen);
    $cipher = substr($ciphertext, $ivlen);
    $plaintext = openssl_decrypt($cipher, $algo, $key, $options=OPENSSL_RAW_DATA, $iv);
    return $plaintext;
}
