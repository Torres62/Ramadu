package br.edu.usf.poo;

import java.util.ArrayList;
import java.util.List;

public class Ventilador implements VentiladorListener {

	private String nome;
	private String modelo;
	private int voltagem;
	private POWER rotacao;
	
	List<VentiladorListener> listeners = new ArrayList<>();
	
	public Ventilador() {
		
	}
	
	public enum POWER {
		OFF(0), MIN(1000), MED(2000), MAX(3000);
		
		private int rpm;
		
		private POWER(int rpm) {
			this.rpm = rpm;
		}
		
		public int getRpm() {
			return rpm;
		}
	}
	
	public void setRotacao(POWER rotacao) {
		this.rotacao = rotacao;
		powerChanged(rotacao);
	}
	
	@Override
	public void powerChanged(POWER rotacao) {
		listeners.forEach(listener -> listener.powerChanged(rotacao));
	}
	
	public void addVentiladorListener(VentiladorListener listener) {
		listeners.add(listener);
	}
	
}
