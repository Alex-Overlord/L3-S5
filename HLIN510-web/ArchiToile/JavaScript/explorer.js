// On répertorie dans un objet les listes déjà chargées
// en valeurs : 1 si la liste est affichée, 0 sinon
var listeChargees = {};
// Ajout dans le DOM des nouveaux éléments / noeuds texte

function generationHTML(objet) {
  var html = "";
  if (objet.image) {
    html+= "<li class ='horizontal'>"+objet.nom+"\u00a0\u00a0" ;
    html+="<image id='"+objet.lien+"'> src='"+objet.image+"' width = '50' height='50'> >/img>";
    html+="<image id='"+objet.lien+"'> </ul> </li>" ;
  } else { 
    html+= "<li>"+objet.nom+"</li>"; 
  }
  return html;
}

function ouvertureFermeture() {
  var id = $(this).attr('id');
  if (listeChargees.hasOwnProperty("#liste_"+id)) {
    if (listeChargees["#liste_"+id] == 1) { // la liste est affichée, on la désaffiche
      listeChargees["#liste_"+id] = 0;
      $("#liste_"+id).hide();
    } else { // la liste est désaffichée, on l’affiche
      listeChargees["#liste_"+id] = 1;
      $("#liste_"+id).show();
    }
  } else {
    // la liste n’est pes encore chargée -> $.getJSON()
    $.getJSON('JSON/'+id+".json",function(data) {
      $.each(data,function(entryIndex,entry) {
        var html = generationHTML(entry);
        $("#liste_"+id).append(html);
        $(document.body).on('click','#'+entry['lien'],ouvertureFermeture);
        listeChargees["#liste_"+id] = 1;
      });
    });
  }
};

$().ready(function() {
  // création de la liste de plus haut niveau
  $("body").append("<ul id='listePrincipale' />");
  $.getJSON('chanteurs.json', function(data) {
    $.each(data, function(indice, objet) {
      let html = generationHTML(objet);
      $("#listePrincipale").append(html);
      $(document.body).on('click', '#'+objet.lien, ouvertureFermeture);
    });
  });
});