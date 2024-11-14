const msg = () => {
    let win = document.querySelector("#info");
    win.showModal();
    let close=document.querySelector("#close");
    close.addEventListener(
        "click",() => {
            win.close();
        }
    )
}