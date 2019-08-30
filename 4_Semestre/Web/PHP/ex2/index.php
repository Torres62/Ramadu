<!DOCTYPE html>
<html lang="en" dir="ltr">
  <head>
    <meta charset="utf-8">
    <title></title>
  </head>
  <body>
    <?php
      if (isset($_POST['nome'])) {
        echo "Olá ".$_POST['nome'];
      }
    ?>
    <form action="resultado.php" method="GET">
      Nome:<br>
      <input type="text" name="name" required><br>
      e-mail:<br>
      <input type="email" name="email"><br>
      Sexo:<br>
      <input type="radio" name="sexo" value="fem">
      <input type="radio" name="sexo" value="mas">
      <br>
      <input type="submit" value="Enviar">
    </form>
  </body>
</html>
