package br.edu.usf.poo;

public class Telefone {

	private String area;
	private String ddd;
	private String numero;
	
	public Telefone(String numero) {
		this(null, null, numero);
	}
	
	public Telefone(String area, String ddd, String numero) {
		this.area = area;
		this.ddd = ddd;
		this.numero = numero;
	}
	
	@Override
	public String toString() {
		String ret = "";
		
		if (area != null) {
			ret += "+" + area + " ";
		}
		
		if (ddd != null) {
			ret += "(" + ddd + ") ";
		}
		
		if (numero != null) {
			ret += numero;
		}
		
		return ret;
	}
}
