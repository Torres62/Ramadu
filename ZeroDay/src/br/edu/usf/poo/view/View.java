package br.edu.usf.poo.view;

import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;

import br.edu.usf.poo.Ventilador;

public class View extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 2130967850881666970L;
	
	public View() {
		initComponents();
		
	}
	
	public void addVentilador(Ventilador ventilador) {
		
	}
	
	private void initComponents() {
		panel = new JPanel();
		
		panel.setLayout(new BorderLayout());

		add(panel);
		setPreferredSize(new Dimension(800, 600));
		pack();
	}
	
	private JPanel panel;
}
