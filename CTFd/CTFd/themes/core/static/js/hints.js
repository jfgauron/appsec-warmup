function hint(id) {
    return CTFd.fetch('/api/v1/hints/' + id, {
        method: 'GET',
        credentials: 'same-origin',
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
        }
    }).then(function (response) {
        return response.json();
    });
}


function unlock(params){
    return CTFd.fetch('/api/v1/unlocks', {
        method: 'POST',
        credentials: 'same-origin',
        headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
        },
        body: JSON.stringify(params)
    }).then(function (response) {
        return response.json();
    });
}

function loadhint(hintid) {
    var md = window.markdownit({
        html: true,
    });

    hint(hintid).then(function (response) {
        if (response.data.content) {
            ezal({
                title: "Hint",
                body: md.render(response.data.content),
                button: "Got it!"
            });
        } else {
            ezq({
                title: "Débloquer indice?",
                body: "Êtes-vous sure de vouloir ouvrir cet indice?",
                success: function () {
                    var params = {
                        target: hintid,
                        type: "hints"
                    };
                    unlock(params).then(function (response) {
                        if (response.success) {
                            hint(hintid).then(function(response) {
                                ezal({
                                    title: "Indice",
                                    body: md.render(response.data.content),
                                    button: "OK!"
                                });
                            });
                        } else {
                            ezal({
                                title: "Erreur",
                                body: md.render(response.errors.score),
                                button: "OK!"
                            });
                        }
                    });
                }
            });
        }
    });
}