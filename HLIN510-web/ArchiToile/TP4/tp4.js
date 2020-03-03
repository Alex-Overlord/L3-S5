function creeHexagone(rayon) {
  var points = new Array();
  for (var i=0; i<6; ++i) {
    var angle = i*60*Math.PI/180;
    var x = Math.sin(angle) * rayon;
    var y = -Math.cos(angle) * rayon;
    x = Math.round(x*100)/100;
    y = Math.round(y*100)/100;
    points.push([x,y]);
  }
  return points;
}

console.dir(creeHexagone(100));

function genereDamier(rayon, nbLignes, nbColonnes) {
  let x = 0;
  let y = 0;

  d3.select("#damier").append("svg").attr("width",1000).attr("height",1000).attr("id","svg");
  let hexagone = creeHexagone(rayon);
  // let offset = [1 * (2 * c + 1 + l % 2) * hexaProto[2][2], rayon * (1 + l * (1.5))];

  for (let ligne = 0; ligne < nbLignes; ligne++) {
    for (let colonne = 0; colonne < nbColonnes; colonne++) {
      let listeCoord = "";
      let offset = 50; //[(2 * colonne + 1 + ligne % 2) * hexagone[2][2], rayon * (1 + ligne * (1.5))];
          
      for (h in hexagone) { // h chaque point de l'hexagone
        if (ligne % 2) { // Si ligne impair, décallage des hexagones d'un rayon 
          x = offset + hexagone[h][0] + (colonne * (rayon * 2)) + rayon;
        } else {
          x = offset + hexagone[h][0] + (colonne * (rayon * 2));
        }
        y = hexagone[h][1] + (ligne * (rayon * 2)) + 50;
          listeCoord = listeCoord + x + "," + y + " ";
        }
        d3.select("#svg").append("polygon")
          .attr("points",listeCoord)
          .attr("fill","blue")
          .attr("stroke","black");
      }
  }
}

genereDamier(50,3,5);

// function genereDamier(rayon, lignes, colonnes) {
//   d3.select("#damier").append("svg").attr("width", 500).attr("height", 500);
//   let hexaProto = creeHexagone(rayon);
  
//   for (let l=0; l<lignes; l++) {
//     for (let c=0; c<colonnes; c++) {
//       let offset = [1 * (2 * c + 1 + l % 2) * hexaProto[2][2], rayon * (1 + l * (1.5))];
//       let listeCoord = "";
      
//       for (let h of hexaProto) {
//         listeCoord += (h[0] + offset[0]) + "," + (h[1] + offset[1]) + " ";
//       }

//       d3.select("svg")
//         .append("polygone")
//         .attr("points", listeCoord.substr(0,listeCoord.length-1))
//         .attr("stroke", "black")
//         .attr("fill", "blue")
//         .on("click", function() {
//           console.log("Clicked! (" + d3.select(this).attr("id") + ")");
//           d3.select(this).attr("fill","purple");
//       });
//     }
//   }
// }

// genereDamier(30, 10, 10);