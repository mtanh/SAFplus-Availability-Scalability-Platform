/**
 * 
 */
package com.clovis.cw.editor.ca.pm;

import org.eclipse.swt.events.ExpandEvent;
import org.eclipse.swt.events.ExpandListener;
import org.eclipse.swt.widgets.ExpandItem;

/**
 * Listener for the expand bar of the PM Editor right pane.
 * 
 * @author Suraj Rajyaguru
 * 
 */
public class PMExpandBarListener implements ExpandListener {

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.eclipse.swt.events.ExpandListener#itemCollapsed(org.eclipse.swt.events.ExpandEvent)
	 */
	public void itemCollapsed(ExpandEvent e) {
	}

	/*
	 * (non-Javadoc)
	 * 
	 * @see org.eclipse.swt.events.ExpandListener#itemExpanded(org.eclipse.swt.events.ExpandEvent)
	 */
	public void itemExpanded(ExpandEvent e) {
		ExpandItem selectedItem = (ExpandItem) e.item;
		ExpandItem items[] = selectedItem.getParent().getItems();

		int totalHeaderHeight = selectedItem.getHeaderHeight() * items.length
				+ 4 * items.length;
		int availabelHeight = selectedItem.getParent().getSize().y
				- totalHeaderHeight;
		selectedItem.setHeight(availabelHeight);

		for (int i = 0; i < items.length; i++) {
			if (!items[i].equals(selectedItem)) {
				items[i].setExpanded(false);
			}
		}
	}
}
