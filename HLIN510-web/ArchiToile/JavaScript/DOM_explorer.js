function analyseDOM(noeud, prof) {
  if (noeud == null) return;
  let type = 0;
  switch (noeud.nodeType) {
    case 1 : 
      type = 'Document'; 
      couleur = 'Yellow';
      console.log("ceci est un Document");      
      break;

    case 2 : 
      type = 'Element'; 
      couleur = 'Steelblue';
      console.log("ceci est un Element");      
      break;

    case 3 : 
      type = 'Text'; 
      couleur = 'Lightgreen';
      console.log("ceci est un Text");      
      break;

    case 4 : 
      type = 'Attribut'; 
      couleur = 'Chocolate';
      console.log("ceci est un Attribut");      
      break;
  } if (type) {
    //visualiserLeNoeud(couleur/*, ... */);
  }
  if (noeud.attributes) {
    for (let num=0; num < noeud.attributes.length; num++) {
      //visualiserLeNoeud('orange'/*, ... */);
    }
  }

  for (let num=0; num < noeud.childNodes.length; num++) {
    analyseDOM(noeud.childNodes.item(num), prof+1);
  }
}

analyseDOM(document, 10);