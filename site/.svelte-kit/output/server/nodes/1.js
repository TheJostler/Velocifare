

export const index = 1;
let component_cache;
export const component = async () => component_cache ??= (await import('../entries/fallbacks/error.svelte.js')).default;
export const imports = ["_app/immutable/nodes/1.-wCcYCVg.js","_app/immutable/chunks/scheduler.zMJaRgub.js","_app/immutable/chunks/index.ZLPrqq-8.js","_app/immutable/chunks/entry.eMxFEJD6.js"];
export const stylesheets = [];
export const fonts = [];
