function send_response()
    ts.client_response.header['CStatus'] = ts.ctx['cstatus']
end

function send_data() 
--    local resp = 'HTTP/1.1 200 OK\r\n' ..
--        'Server: ATS/3.2.0-miss\r\n'
--    return resp
    local nt = os.time()..' Zheng.\n'
    local resp =  'HTTP/1.1 404 Not Found\r\n' ..
        'Server: ATS/3.2.0\r\n' ..
        'Content-Type: text/plain\r\n' ..
        'Content-Length: ' .. string.len(nt) .. '\r\n' ..
        'Last-Modified: ' .. os.date("%a, %d %b %Y %H:%M:%S GMT", os.time()) .. '\r\n' ..
        'Connection: keep-alive\r\n' ..
        'Cache-Control: max-age=7200\r\n' ..
        'Accept-Ranges: bytes\r\n\r\n' ..
        nt

   --  ts.sleep(1)
    return resp
end


function cache_lookup()
    local cache_status = ts.http.get_cache_lookup_status()
    if cache_status == TS_LUA_CACHE_LOOKUP_HIT_FRESH or  cache_status == TS_LUA_CACHE_LOOKUP_HIT_STALE then
        ts.ctx['cstatus'] = 'hit'
    else
        ts.ctx['cstatus'] = 'nothit'
        ts.http.intercept(send_data)
    end
end


function do_remap()
    -- ts.http.intercept(send_data)
     ts.hook(TS_LUA_HOOK_SEND_RESPONSE_HDR, send_response)
    
     ts.hook(TS_LUA_HOOK_CACHE_LOOKUP_COMPLETE, cache_lookup)
    return 0
end
