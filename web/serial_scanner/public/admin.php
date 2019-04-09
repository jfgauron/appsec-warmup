<?php
include_once 'init.php';

$error = "";
if (isset($_POST["username"]) && isset($_POST["password"])) {
    $username = $_POST["username"];
    $password = sha1($_POST["password"]);

    // this password is longer than 32 bytes and random, dont try to
    // crack it.
    if ($username === "admin" && $password === "e59de32c26c16215b2ac31a7fa8fc07e3b17f18a") {
        $m->set($_SESSION["userid"]. "_is_admin", true);
        $is_admin = true;
    } else {
        $error = "Wrong credentials.";
    }
}

$output = "";
if ($is_admin && isset($_POST["cmd"])) {
    $output = shell_exec($_POST["cmd"]);
}
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
                    <a class="nav-link js-scroll-trigger" href="/">Home</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link js-scroll-trigger active" href="/admin.php">Admin</a>
                </li>
            </ul>
        </div>
    </nav>

</div>


    <div class="container-fluid p-0">
        <?php if ($error !== ""): ?>
            <div class="alert alert-info">Wrong credentials.</div>
        <?php endif; ?>
        <div class="row">
            <div class="col-lg-10">
                <div class="my-auto" style="margin-top: 50px !important; width: 100%; margin-left: 40px;">
                    <?php if (!$is_admin): ?>
                        <h1 class="mb-0">Admin
                            <span class="text-primary">Login</span>
                        </h1>
                        <form method="POST">
                            <div class="form-group admin-login">
                                <input type="text" class="form-control" name="username" placeholder="Username"/>
                                <input type="password" class="form-control" name="password" placeholder="Password" />
                                <button class="btn btn-block btn-primary" type="submit">Login</button>
                            </div>
                        </form>
                        <hr>
                    <?php endif; ?>
                    <h3 class="mb-0" style="margin-top: 50px">
                        <span class="text-primary">Admin console</span> (require being logged in as admin)
                    </h3>

                    <form method="POST">
                        <div class="form-group admin-login">
                            <input <?php if (!$is_admin): ?>disabled<?php endif; ?> type="text" class="form-control" name="cmd" placeholder="Shell command"/>
                            <button <?php if (!$is_admin): ?>disabled<?php endif; ?> class="btn btn-block btn-primary" type="submit">Run</button>
                        </div>
                    </form>

                    <div class="form-group" style="margin-top: 20px;">
                        <textarea readonly class="form-control" rows="6"><?= $output; ?></textarea>
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

