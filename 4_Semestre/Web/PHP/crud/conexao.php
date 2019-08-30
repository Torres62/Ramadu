<?php
  /**
   * Classe conexão
   */
  class Conexao
  {
    private $db = "aula_web";
    private $user = "root";
    private $senha = "";
    private $servidor = "localhost";

    public $conn;

    public function __construct()
    {
      try {
        $this->conn = new PDO(
          "mysql:host=".$this->servidor.";dbname=".$this->db,
          $this->user,
          $this->senha
        );
        $this->conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

        echo "CONECTED!";
      } catch (PDOExeption $e) {
        echo "ERRO: ".$e->getMessage();
      }
    }
  }
?>
