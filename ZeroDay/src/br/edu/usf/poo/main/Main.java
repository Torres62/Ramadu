package br.edu.usf.poo.main;

import java.awt.EventQueue;

import javax.swing.UIManager;

import br.edu.usf.poo.Ventilador;
import br.edu.usf.poo.Ventilador.POWER;
import br.edu.usf.poo.view.View;


public class Main {

	public static void main(String[] args) {
		EventQueue.invokeLater(() -> {
			try {
				UIManager.setLookAndFeel(UIManager.getSystemLookAndFeelClassName());

				Ventilador vent = new Ventilador();
				vent.setRotacao(POWER.MED);
				
				View view = new View();
				view.addVentilador(vent);
				view.setVisible(true);
				
			} catch (Exception e) {
				e.printStackTrace();
			}
		});
	}

}
