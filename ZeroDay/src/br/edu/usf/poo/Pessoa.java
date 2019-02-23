package br.edu.usf.poo;

import java.util.List;

public class Pessoa {

	private String cpf;
	private String nome;
	private Endereco endereco;
	private List<Telefone> telefones;
	
	public Pessoa(String cpf, String nome) {
		this(cpf, nome, null, null);
	}
	
	public Pessoa(String cpf, String nome, Endereco endereco, List<Telefone> telefones) {
		this.cpf = cpf;
		this.nome = nome;
		this.endereco = endereco;
		this.telefones = telefones;
	}
	
	public String getCPF() {
		return cpf;
	}
	
	public String getNome() {
		return nome;
	}
	
	public Endereco getEndereco() {
		return endereco;
	}
	
	public void setEndereco(Endereco endereco) {
		this.endereco = endereco;
	}
	
	public void addTelefone(Telefone telefone) {
		telefones.add(telefone);
	}
	
	public void removeTelefone(Telefone telefone) {
		telefones.remove(telefone);
	}
	
}
