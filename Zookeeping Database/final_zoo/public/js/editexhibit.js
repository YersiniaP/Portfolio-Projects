function editexhibit(exhibit_id){
    $.ajax({
        url: '/exhibits/' + exhibit_id,
        type: 'PUT',
        // params: {exhibit_id, species_in_exhibit11},
        data: $('#text_box1').serialize(),
        success: function(result){
            window.location.reload(true);
        }
    })
};