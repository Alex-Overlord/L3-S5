var http = "https://webpeda.etu.umontpellier.fr/e20170006075/ArchiToile/TP3/JSON/";
var tab_tmp;

$.getJSON(http + "themes.json", function(data) {
  var map = new ol.Map({
  target: 'map',
  layers: [new ol.layer.Tile({source: new ol.source.OSM()})],
  view: new ol.View({
    center: new ol.proj.fromLonLat([3.876716,43.61]),
    zoom: 14
  })
  });

  let marker = document.getElementById('marker');
  map.addOverlay(new ol.Overlay({
  position: new ol.proj.fromLonLat([3.8766716,43.6141]),
  positioning: 'center-center',
  element: marker
  }));

  var tab_data = [];
  data.forEach(function(o) {
    var tab_inter = [];
    $.getJSON(http + o.lien, function(l) {
      tab_tmp = [];
      l.forEach(function(e) {
        tab_tmp.push(e);
      });
      tab_inter.push(o.nom);
      tab_inter.push(tab_tmp);
      tab_data.push(tab_inter);
    })
  });
  console.log(tab_data); // debug
});