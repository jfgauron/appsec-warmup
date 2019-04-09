<?php
// FLAG-ab474baa184f4642ad9a5d922ad6e212
session_start();

$infos  = "";
$status = "success";

$nb_images = 16;
for ($i = 0; $i < $nb_images; $i++) {
    if (!isset($_SESSION["image".$i])) {
        $_SESSION["image".$i] = "image/empty.png";
        $_SESSION["nb_images"] = 0;
    }
}

if (!isset($_SESSION["folder"])) {
    $folder = "/uploads/" . bin2hex(random_bytes(16)) . "/";
    mkdir(__DIR__ . $folder);
    $_SESSION["folder"] = $folder;
}

if (isset($_SERVER['CONTENT_LENGTH'])
 && (int) $_SERVER['CONTENT_LENGTH'] > (1024*1024*(int) ini_get('post_max_size')))
{
    $infos  = "Your file is over 2 MB.";
    $status = "danger";
}

if (isset($_FILES["photo"])) {
    $status = "danger";

    if ($_FILES['photo']['error'] === UPLOAD_ERR_INI_SIZE
        || $_FILES["photo"]["size"] > 2000000)
    {
        $infos = "Your file is over 2 MB.";
    } else if (!file_exists($_FILES["photo"]["tmp_name"])
            || !is_uploaded_file($_FILES["photo"]["tmp_name"])) {
        $infos = "No file was uploaded.";
    } else {
        $filename = basename($_FILES["photo"]["name"]);
        $target_file = __DIR__ . $_SESSION["folder"] . $filename;

        $finfo = finfo_open(FILEINFO_MIME_TYPE);
        $mime = finfo_file($finfo, $_FILES["photo"]["tmp_name"]);
        if (($mime !== "image/png")
         || ($_FILES["photo"]["type"] != "image/png")
         || (strrpos($target_file, ".png") === false)) {
            $infos = "Only png files are accepted.";
        }
        finfo_close($finfo);

        if ($infos === "") {
            if (!move_uploaded_file($_FILES["photo"]["tmp_name"], $target_file)) {
                $infos = "An error happened when uploading your file.";
            } else {
                $infos = "Successfully uploaded your file.";
                $status = "success";
                $_SESSION["image".($_SESSION["nb_images"]%$nb_images)] = $_SESSION["folder"] . $filename;
                $_SESSION["nb_images"] += 1;
            }
        }
    }
}
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="utf-8">
    <meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
    <title>Photo gallery</title>
    <!-- Bootstrap core CSS -->
    <link href="vendor/bootstrap/css/bootstrap.min.css" rel="stylesheet">
    <!-- Custom styles for this template -->
    <link href="css/thumbnail-gallery.css" rel="stylesheet">
</head>

<body>

    <style>
        .custom-form {
            margin-top: 20px;
            margin-bottom: 20px;
        }
    </style>

    <!-- Navigation -->
    <nav class="navbar navbar-expand-lg navbar-dark bg-dark fixed-top">
        <div class="container">
            <a class="navbar-brand" href="/">Photo gallery v4.1</a>
            <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarResponsive" aria-controls="navbarResponsive" aria-expanded="false" aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
        </div>
    </nav>

    <!-- Page Content -->
    <div class="container">

        <form class="custom-form" method="POST" enctype="multipart/form-data">
            <?php if ($infos !== ""): ?>
                <div class="alert alert-<?= $status; ?>" role="alert">
                    <?= $infos; ?>
                </div>
            <?php endif; ?>

            <div class="input-group">
                <div class="input-group-prepend">
                    <button class="btn btn-primary" type="submit">Upload</button>
                </div>
                <div class="custom-file">
                    <input type="file" class="custom-file-input" id="photo" name="photo">
                    <label class="custom-file-label" for="photo">Choose a PNG file...</label>
                </div>
            </div>
        </form>

        <div class="row text-center text-lg-left">

            <?php for ($i = 0; $i < $nb_images; $i++): ?>
                <div class="col-lg-3 col-md-4 col-xs-6">
                    <a class="d-block mb-4 h-100">
                        <img class="img-fluid img-thumbnail" src="<?= $_SESSION["image".$i]; ?>" alt="photo">
                    </a>
                </div>
            <?php endfor; ?>
        </div>

    </div>
    <!-- /.container -->

    <!-- Bootstrap core JavaScript -->
    <script src="vendor/jquery/jquery.min.js"></script>
    <script src="vendor/bootstrap/js/bootstrap.bundle.min.js"></script>
    <script type="application/javascript">
        $('input[type="file"]').change(function(e){
        var fileName = e.target.files[0].name;
        $('.custom-file-label').html(fileName);
        });
    </script>

</body>

</html>
