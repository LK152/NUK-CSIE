import './index.css'
import React from 'react';
import ReactDOM from 'react-dom/client';
import App from './App';
import Map from './Map';
import { BrowserRouter as Router, Routes, Route } from 'react-router-dom';
import 'leaflet/dist/leaflet.css'

const root = ReactDOM.createRoot(
	document.getElementById('root') as HTMLElement
);

root.render(
	<React.StrictMode>
		<Router>
			<Routes>
				<Route path='/' element={<App />} />
				<Route path='/map' element={<Map />} />
			</Routes>
		</Router>
	</React.StrictMode>
);
