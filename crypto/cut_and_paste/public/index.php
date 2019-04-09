<?php
include_once 'crypto.php';

set_error_handler(function($errno, $errstr, $errfile, $errline, array $errcontext) {
    // error was suppressed with the @-operator
    if (0 === error_reporting()) {
        return false;
    }
    throw new ErrorException($errstr, 0, $errno, $errfile, $errline);
});

if (isset($_POST["username"])) {
    $_POST["username"] = substr($_POST["username"], 0, 128);
    $cookie = "username=".$_POST["username"]."&role=guest";
    $encrypted_cookie = encrypt($cookie);
    $_COOKIE["data"] = $encrypted_cookie;
    setcookie("data", $encrypted_cookie);
}

if (isset($_POST["data"])) {
    $_COOKIE["data"] = $_POST["data"];
    setcookie("data", $_COOKIE["data"]);
}

if (!isset($_COOKIE["data"])) {
    $cookie = "username=anonymous&role=guest";
    $encrypted_cookie = encrypt($cookie);
    $_COOKIE["data"] = $encrypted_cookie;
    setcookie("data", $encrypted_cookie);
}

$info = array();
$error = "";
try {
    $cookie = decrypt($_COOKIE["data"]);
} catch (Exception $e) {
    $error = "Could not decrypt cookie, values reinitialized.";
    $cookie = "username=anonymous&role=guest";
    $encrypted_cookie = encrypt($cookie);
    $_COOKIE["data"] = $encrypted_cookie;
    setcookie("data", $encrypted_cookie);
    $cookie = decrypt($_COOKIE["data"]);
}
parse_str($cookie, $info);

$success = false;
if ($info["role"] === "admin") {
    $success = true;
}
?>

<!DOCTYPE html>
<html lang="en">

  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>Cut & Paste</title>

    <!-- Bootstrap core CSS -->
    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom fonts for this template -->
    <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet">
    <link href="vendor/simple-line-icons/css/simple-line-icons.css" rel="stylesheet" type="text/css">

    <!-- Custom styles for this template -->
    <link href="css/landing-page.min.css" rel="stylesheet">
    <link href="css/style.css" rel="stylesheet">
  </head>

  <body>
    <div class="h-100 d-flex flex-column">

        <!-- Navigation -->
        <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
            <div class="container">
                <a class="navbar-brand" href="#">Cut & Paste</a>
            </div>
        </nav>

        <!-- Masthead -->
        <header class="masthead text-white text-center flex-grow-1">
            <div class="overlay"></div>
            <div class="container">
                <?php if (!$success): ?>
                    <div class="alert alert-danger" role="alert">
                        Set your role to "admin" to get the flag.
                    </div>
                <?php else: ?>
                    <div class="alert alert-success" role="alert">
                        Good job! Here is your flag: FLAG-b9c0135acd80f949ed33a92766bd0850
                    </div>
                <?php endif; ?>

                <div class="row">
                    <div class="col-xl-6 mx-auto" style="margin-bottom: 20px">
                        <div class="card user-information text-left">
                            <div class="card-header">
                                <h5>Personal information</h5>
                            </div>
                            <div class="card-body">
                                <?php if (isset($_POST["username"])): ?>
                                    <div class="alert alert-info" role="alert">
                                        Username changed.
                                    </div>
                                <?php endif; ?>
                                <p><strong>Username:</strong> <?= $info["username"] ?></p>
                                <p><strong>Role:</strong> <?= $info["role"] ?></p>
                                <?php if (isset($_POST["debug"]) && $_POST["debug"] === "true"): ?>
                                <?php endif; ?>
                            </div>
                        </div>
                        <div class="col-xl-12 mx-auto">
                            <form method="POST">
                                <div class="form-row">
                                    <div class="col-12 col-md-9 mb-2 mb-md-0">
                                        <input type="text" name="username" class="form-control form-control-lg" placeholder="Change username" maxlength="128">
                                    </div>
                                    <div class="col-12 col-md-3">
                                        <button type="submit" class="btn btn-block btn-lg btn-primary">Update</button>
                                    </div>
                                </div>
                            </form>
                        </div>
                    </div>
                    <div class="col-xl-6 mx-auto">
                        <div class="card user-information text-left">
                            <div class="card-header">
                                <h5>Cookie</h5>
                            </div>
                            <div class="card-body">
                                <?php if (isset($_POST["data"])): ?>
                                    <div class="alert alert-info" role="alert">
                                        <?php if ($error !== ""): ?>
                                            <?= $error; ?>
                                        <?php else: ?>
                                            Data changed.
                                        <? endif; ?>
                                    </div>
                                <?php endif; ?>
                                <p><strong>data:</strong> <?= $_COOKIE["data"] ?></p>
                                <p><strong>data (decrypted):</strong> <?= $cookie; ?></p>
                            </div>
                        </div>
                        <div class="col-xl-12 mx-auto">
                            <form method="POST">
                                <div class="form-row">
                                    <div class="col-12 col-md-9 mb-2 mb-md-0">
                                        <input type="text" name="data" class="form-control form-control-lg" placeholder="Change data">
                                    </div>
                                    <div class="col-12 col-md-3">
                                        <button type="submit" class="btn btn-block btn-lg btn-primary">Update</button>
                                    </div>
                                </div>
                            </form>
                        </div>
                    </div>
                </div>
            </div>
        </header>
    </div>

    <!-- Bootstrap core JavaScript -->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
  </body>

</html>
