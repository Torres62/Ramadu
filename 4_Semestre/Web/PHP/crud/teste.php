<?php
  require 'conexao.php';
  $conectado = new Conexao();
  $stm = $conectado->conn->prepare(
    "INSERT INTO Alunos( ".
      "nome, ".
      "dt_nasc, ".
      "cpf ".
    ") ".
    "VALUES( ".
      ":n, ".
      ":i,".
      ":t ".
    ");"
  );
  $stm->bindValue(":n", "Eduwardo");
  $stm->bindValue(":i", "1000-01-01 00:00:00.000000");
  $stm->bindValue(":t", "c");

  $output = $stm->execute();

  echo $output
?>
