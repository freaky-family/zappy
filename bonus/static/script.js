async function poll()
{
    const data = await fetch('/state').then(r => r.json());
    const cells = {};
    const resources = data.resources;
    let html = '';

    if (!data.width)
        return;
    document.getElementById('info').textContent =
        `${data.width}x${data.height} | teams: ${data.teams.join(', ')} | players: ${Object.keys(data.players).length}`;
    for (const [id, p] of Object.entries(data.players))
        cells[`${p.x},${p.y}`] = (cells[`${p.x},${p.y}`] || '') + `#${id}`;
    for (let y = 0; y < data.height; y++) {
        html += '<tr>';
        for (let x = 0; x < data.width; x++) {
            const p = cells[`${x},${y}`];
            const r = resources[`${x},${y}`];
            html += `<td class="${p ? 'player' : ''}">
                        <a href="/tile/${x}/${y}">${p || ''}</a>
                        <table>
                            <tr>
                                <td class="${r && r[0] ? 'food' : p ? 'playerl' : 'default'}"></td>
                            </tr>
                            <tr>
                                <td class="${r && r[1] ? 'linemate' : p ? 'playerl' : 'default'}"></td>
                                <td class="${r && r[2] ? 'deraumere' : p ? 'playerl' : 'default'}"></td>
                                <td class="${r && r[3] ? 'sibur' : p ? 'playerl' : 'default'}"></td>
                            </tr>
                            <tr>
                                <td class="${r && r[4] ? 'mendiane' : p ? 'playerl' : 'default'}"></td>
                                <td class="${r && r[5] ? 'phiras' : p ? 'playerl' : 'default'}"></td>
                                <td class="${r && r[6] ? 'thystame' : p ? 'playerl' : 'default'}"></td>
                            </tr>
                        </table>
                    </td>`;
        }
        html += '</tr>';
    }
    document.getElementById('map').innerHTML = html;
}
setInterval(poll, 1000);
poll();
