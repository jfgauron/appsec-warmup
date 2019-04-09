<?php
if (!isset($scans) || !isset($_GET["scan"]) || !array_key_exists($_GET["scan"], $scans)) {
    header('Location: /');
    exit();
}

$scan = $scans[$_GET["scan"]];
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Scanner</title>

    <!-- Bootstrap core CSS -->
    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">

    <!-- Custom fonts for this template -->
    <link href="https://fonts.googleapis.com/css?family=Saira+Extra+Condensed:500,700" rel="stylesheet">
    <link href="https://fonts.googleapis.com/css?family=Muli:400,400i,800,800i" rel="stylesheet">
    <link href="vendor/fontawesome-free/css/all.min.css" rel="stylesheet">

    <!-- Custom styles for this template -->
    <link href="css/resume.min.css" rel="stylesheet">
    <link href="css/style.css" rel="stylesheet">
</head>

<body id="page-top">

    <nav class="navbar navbar-expand-lg navbar-dark bg-primary fixed-top" id="sideNav">
        <a class="navbar-brand js-scroll-trigger" href="#page-top">
            <span class="d-block d-lg-none">Scanner as a service</span>
        </a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>
        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav">
                <li class="nav-item">
                    <span class="nav-link">id #<?= $_SESSION["userid"]; ?></span>
                </li>
                <li class="nav-item">
                    <a class="nav-link js-scroll-trigger active" href="/">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link js-scroll-trigger" href="/admin.php">Admin</a>
                </li>
            </ul>
        </div>
    </nav>

</div>


    <div class="container-fluid p-0">

        <div class="row">
            <div class="col-lg-10">
                <div class="my-auto" style="margin-top: 50px !important; width: 100%; margin-left: 40px;">
                    <h1 class="mb-0">Go
                        <a href="/" class="text-primary">back</a>
                    </h1>
                    <hr>
                </div>
            </div>
        </div>

        <div class="row">
            <div class="col-lg-10">
                <div class="my-auto" style="margin-top: 40px !important; width: 100%; margin-left: 40px;">
                    <h3 class="mb-0">
                        <span class="text-primary"><?= htmlentities($scan["url"]); ?></span>
                    </h3>

                    <div class="card">
                        <div class="card-body">
                            <?= htmlentities($scan["response"]); ?>
                        </div>
                    </div>

                    <h3 class="mb-0" style="margin-top: 20px;">
                        <span>Error(s)</span>
                    </h3>

                    <div class="card">
                        <div class="card-body">
                            <?= htmlentities($scan["error"]); ?>
                        </div>
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
