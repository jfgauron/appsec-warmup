<?php
require_once "secrets.php";

if (isset($_GET["code"])) {
    echo highlight_file("index.php");
    exit();
}

$result = "";
if (isset($_POST["data"])) {
    $data = $_POST["data"] . $flag;
    $result = bin2hex(mcrypt_encrypt(
        MCRYPT_RIJNDAEL_128,
        $key,
        $data,
        MCRYPT_MODE_ECB
    ));
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Encrypt</title>

    <!-- Bootstrap core CSS -->
    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom fonts for this template -->
    <link href="https://fonts.googleapis.com/css?family=Saira+Extra+Condensed:500,700" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Muli:400,400i,800,800i" rel="stylesheet">
    <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet">

    <!-- Custom styles for this template -->
    <link href="css/resume.min.css" rel="stylesheet">
</head>

<body id="page-top">

    <nav class="navbar navbar-expand-lg navbar-dark bg-primary fixed-top" id="sideNav">
        <a class="navbar-brand js-scroll-trigger" href="#page-top">
            <span class="d-block d-lg-none">Encryption as a Service</span>
        </a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav">
                <li class="nav-item">
                    <a class="nav-link js-scroll-trigger active" href="/">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link js-scroll-trigger" href="/?code">Source code</a>
                </li>
            </ul>
        </div>
    </nav>

    <div class="container-fluid p-0">

        <div class="row">
            <div class="col-lg-10">
                <div class="my-auto" style="margin-top: 200px !important; width: 100%; margin-left: 40px;">
                    <h1 class="mb-0">Encryption
                        <span class="text-primary">as a Service</span>
                    </h1>

                    <form method="POST">
                        <div class="form-group" style="margin-top: 20px;">
                            <label for="data">What do you wish to encrypt?</label>
                            <textarea class="form-control" id="data" name="data" rows="3"></textarea>
                        </div>
                        <button class="btn btn-block btn-primary" type="submit">Encrypt!</button>
                    </form>
                </div>
            </div>
        </div>

        <div class="row">
            <div class="col-lg-10">
                <div class="my-auto" style="margin-top: 40px !important; width: 100%; margin-left: 40px;">
                    <h3 class="mb-0">
                        <span class="text-primary">Result</span>
                    </h3>

                    <div class="form-group" style="margin-top: 20px;">
                        <textarea readonly class="form-control" id="exampleTextarea" rows="3" id="result"><?= $result ?></textarea>
                    </div>
                </div>
            </div>
        </div>

    </div>

    <!-- Bootstrap core JavaScript -->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>

    <!-- Plugin JavaScript -->
    <script src="vendor/jquery-easing/jquery.easing.min.js"></script>

</body>

</html>
