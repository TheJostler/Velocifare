export const manifest = (() => {
function __memo(fn) {
	let value;
	return () => value ??= (value = fn());
}

return {
	appDir: "_app",
	appPath: "_app",
	assets: new Set(["favicon.png"]),
	mimeTypes: {".png":"image/png"},
	_: {
		client: {"start":"_app/immutable/entry/start.4AsR4VTF.js","app":"_app/immutable/entry/app.tVVbNdpz.js","imports":["_app/immutable/entry/start.4AsR4VTF.js","_app/immutable/chunks/entry.eMxFEJD6.js","_app/immutable/chunks/scheduler.zMJaRgub.js","_app/immutable/entry/app.tVVbNdpz.js","_app/immutable/chunks/scheduler.zMJaRgub.js","_app/immutable/chunks/index.ZLPrqq-8.js"],"stylesheets":[],"fonts":[],"uses_env_dynamic_public":false},
		nodes: [
			__memo(() => import('./nodes/0.js')),
			__memo(() => import('./nodes/1.js'))
		],
		routes: [
			
		],
		matchers: async () => {
			
			return {  };
		},
		server_assets: {}
	}
}
})();
