<?php
session_start();

if (!isset($_SESSION["userid"])) {
    $userid = '';
    for($i = 0; $i < 8; $i++) {
        $userid .= rand(0,9);
    }
    $_SESSION["userid"] = $userid;
}

$m = new Memcached();
$m->addServer('127.0.0.1', 11211);

$scans = $m->get($_SESSION["userid"] . "_scans");
if (!$scans) {
    $scans = "[]";
}
$scans = json_decode($scans, true);

$is_admin = $m->get($_SESSION["userid"] . "_is_admin");
if (!$is_admin) {
    $is_admin = false;
}