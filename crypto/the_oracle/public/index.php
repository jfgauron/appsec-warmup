<?php
include_once 'crypto.php';

$predictions = array(
    array("I see a lot of flags in your future!", "No, none at all."),
    array("You are about to become very rich.", "You will lose all your money."),
    array("All your dreams will come true. Yes, even the weird ones.", 'Ehh...Define "successful".')
);

function reset_cookie() {
    $cookie = "Sight=0";
    $enc    = encrypt($cookie);
    $_COOKIE["customer_info"] = $enc;
    setcookie("customer_info", $enc);
}

if (!isset($_COOKIE["customer_info"])) {
    reset_cookie();
}

$errors = array();
if (isset($_COOKIE["customer_info"])) {
    $_COOKIE["customer_info"] = decrypt($_COOKIE["customer_info"]);
    while ($msg = openssl_error_string()) {
        $errors = array("AES-256-CBC PKCS#7 PADDING error.");
    }
}

if (count($errors) > 0) {
    reset_cookie();
}

$info = array();
parse_str($_COOKIE["customer_info"], $info);

if (count($_POST) > 0) {
    $chance = rand() % 2;
}
?>

<!DOCTYPE html>
<html lang="en">

  <head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">

    <title>The Oracle</title>

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
        <nav class="navbar navbar-expand-lg navbar-dark bg-dark" style="background-color: black !important">
            <div class="container" style="text-align: center">
                <div style="margin: auto;">
                    <img src="img/fire.gif" height=50 width=50>
                    <img src="img/fire.gif" height=50 width=50>
                    <img src="img/fire.gif" height=50 width=50>
                    <h1 style="color: white; display: inline">The Oracle</h1>
                    <img src="img/fire.gif" height=50 width=50>
                    <img src="img/fire.gif" height=50 width=50>
                    <img src="img/fire.gif" height=50 width=50>
                </div>
            </div>
        </nav>

        <!-- Masthead -->
        <header class="masthead text-white text-center flex-grow-1">
            <div class="container" style="max-width: 100%">
                <?php if (count($errors) > 0): ?>
                    <div class="alert alert-danger errorbox">
                        <?php foreach ($errors as $error): ?>
                            <?= $error ?>
                        <? endforeach; ?>
                    </div>
                <?php endif; ?>
                <div class="row">
                    <div class="col-xl-5 offset-xl-1">
                        <div class="card user-information text-left">
                            <div class="card-header">
                                <h5>Welcome, to the Oracle's Lair!</h5>
                            </div>
                            <div class="card-body">
                                <p>What is it you want to know about your future? Ask and I shall tell you!</p>
                                <form method="POST" action="">
                                    <button type="submit" class="btn btn-block btn-lg btn-dark" name="money">How much money will I make this year?</button>
                                    <?php if (isset($_POST["money"])): ?>
                                        <div class="alert alert-danger"><?= $predictions[1][$chance]; ?></div>
                                    <?php endif; ?>
                                    <button type="submit" class="btn btn-block btn-lg btn-dark" name="flags">Will I get many flags in CTFs?</button>
                                    <?php if (isset($_POST["flags"])): ?>
                                        <div class="alert alert-danger"><?= $predictions[0][$chance]; ?></div>
                                    <?php endif; ?>
                                    <button type="submit" class="btn btn-block btn-lg btn-dark" name="life">Will I live a successful live?</button>
                                    <?php if (isset($_POST["life"])): ?>
                                        <div class="alert alert-danger"><?= $predictions[2][$chance]; ?></div>
                                    <?php endif; ?>
                                    <button type="submit" class="btn btn-block btn-lg btn-dark" name="lotto">What is the next winning lottery number?</button>
                                    <?php if (isset($_POST["lotto"])): ?>
                                        <div class="alert alert-danger">
                                            <?php if ($info["Sight"]): ?>
                                                Okay, I lied about the lottery number. Here is a flag for your trouble: FLAG{43315d9819c432f66cf6b1e0c9c8c16f}
                                            <?php else: ?>
                                                Sorry, but only customers who have the Sight&trade; can know that. You don't.
                                            <?php endif; ?>
                                        </div>
                                    <?php endif; ?>
                                </form>
                            </div>
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
