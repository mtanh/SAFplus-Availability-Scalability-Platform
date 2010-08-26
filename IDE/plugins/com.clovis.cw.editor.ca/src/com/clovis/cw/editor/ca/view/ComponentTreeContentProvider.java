/*******************************************************************************
 * ModuleName  : com
 * $File: //depot/dev/main/Andromeda/IDE/plugins/com.clovis.cw.editor.ca/src/com/clovis/cw/editor/ca/view/ComponentTreeContentProvider.java $
 * $Author: bkpavan $
 * $Date: 2007/01/03 $
 *******************************************************************************/

/*******************************************************************************
 * Description :
 *******************************************************************************/


package com.clovis.cw.editor.ca.view;

import java.util.HashMap;
import java.util.List;
import java.util.Vector;

import org.eclipse.emf.common.util.EList;
import org.eclipse.emf.ecore.EObject;
import org.eclipse.emf.ecore.EReference;

import com.clovis.common.utils.constants.ModelConstants;
import com.clovis.common.utils.ecore.ClovisNotifyingListImpl;
import com.clovis.common.utils.ecore.EcoreUtils;
import com.clovis.common.utils.ui.tree.TreeContentProvider;
import com.clovis.common.utils.ui.tree.TreeNode;
import com.clovis.cw.editor.ca.constants.ComponentEditorConstants;

/**
 *
 * @author shubhada
 *Component Editor Outline View Tree Content Provider
 */
public class ComponentTreeContentProvider extends TreeContentProvider
{
   private EList _contentList = null;
   /**
   * @param parent - Object
   * @return the top level elements in the tree.
   */
   public Object[] getElements(Object parent)
   {
       _contentList = (EList) parent;
       ClovisNotifyingListImpl elemList = new ClovisNotifyingListImpl();
       EObject rootObject = (EObject) _contentList.get(0);
       List clusterList = (EList) rootObject.eGet(rootObject.eClass().getEStructuralFeature(ComponentEditorConstants.CLUSTER_REF_NAME));
       for (int i = 0; i < clusterList.size(); i++) {
           EObject eobj = (EObject) clusterList.get(i);
           elemList.add(new TreeNode(null, null, eobj));
       }
       return elemList.toArray();
   }
   /**
    * @param parent Object
    * @return the child nodes of parent TreeNode
    */
   public Object [] getChildren(Object parent)
   {
       TreeNode node = (TreeNode) parent;
       Object   obj  =  node.getValue();
       if (!(obj instanceof EObject)) {
           return new Object[0];
       }
       Vector elemList = new Vector();
       Object[] children = super.getChildren(parent);
       for (int i = 0; i < children.length; i++) {
           elemList.add(children[i]);
       }
       elemList.addAll(getChildNodes(node));
       return elemList.toArray();
   }
   /**
    * Get Child Nodes (Complex Children only)
    * @param parent Parent EObject
    * @return list of complex children.
    */
   private List getChildNodes(TreeNode parent)
   {
       EObject parentObj = (EObject) parent.getValue();
       HashMap keyObjMap = new HashMap();
       EObject rootObject = (EObject) _contentList.get(0);
       List refList = rootObject.eClass().getEAllReferences();
       for (int i = 0; i < refList.size(); i++) {
    	   EReference ref = (EReference) refList.get(i);
    	   List list = (EList) rootObject.eGet(ref);
    	   for (int j = 0; j < list.size(); j++) {
               EObject eObj = (EObject) list.get(j);
               String  key  = (String) EcoreUtils.getValue(eObj,
            		   ModelConstants.RDN_FEATURE_NAME);
               keyObjMap.put(key, eObj);
           }
       }
       List list = new Vector();
       List connsList = (EList) rootObject.eGet(rootObject.eClass()
				.getEStructuralFeature(ComponentEditorConstants.AUTO_REF_NAME));
       for (int i = 0; i < connsList.size(); i++) {
           EObject eObj = (EObject) connsList.get(i);
           String type = (String) (String) EcoreUtils.getValue(eObj,
						ComponentEditorConstants.CONNECTION_TYPE);
				if (type.equals(ComponentEditorConstants.CONTAINMENT_NAME)) {
					String src = (String) EcoreUtils.getValue(eObj,
							ComponentEditorConstants.CONNECTION_START);
					if (src.equals(EcoreUtils.getValue(parentObj,
							ModelConstants.RDN_FEATURE_NAME))) {
						String end = (String) EcoreUtils.getValue(eObj,
								ComponentEditorConstants.CONNECTION_END);
						Object targetObj = keyObjMap.get(end);
						if (targetObj != null) {
							list.add(new TreeNode(null, parent, targetObj));
						}
					}
				}
	   }
       return list;
   }

}
